/*
ID: Sfiction
OJ: CF
PROB: 452D
*/
#include <cstdio>

const int MAXK=10000+10,MAXN=1000+10;;

class heap{
    int heap_size;
    int a[MAXN];

    private:
        inline int parent(int i){
            return i>>1;
        }
        inline int left(int i){
            return i<<1;
        }
        inline int right(int i){
            return (i<<1)|1;
        }
        int up(int i){
            int p=parent(i);
            int temp=a[i];
            while (p&&a[p]>temp){
                a[i]=a[p];
                i=p;
                p=parent(i);
            }
            a[i]=temp;
            return i;
        }
        int down(int i){
            int l,r;
            int max;
            int temp=a[i];
            while (i<heap_size){
                l=left(i);
                r=right(i);
                if (l<=heap_size&&a[l]<a[i])
                    max=l;
                else
                    max=i;
                if (r<=heap_size&&a[r]<a[max])
                    max=r;
                if (max==i)
                    break;
                else{
                    a[i]=a[max];
                    a[max]=temp;
                    i=max;
                }
            }
            return i;
        }
    public:
        inline int size(){
            return heap_size;
        }
        inline int maximum(){
            return a[1];
        }
        int add(int num){
            ++heap_size;
            a[heap_size]=num;
            return up(heap_size);
        }
        int pop(){
            int ret=a[1];
            a[1]=a[heap_size];
            --heap_size;
            down(1);
            return ret;
        }
};

heap wash,dry,fold;

int k;
int n1,n2,n3;
int t1,t2,t3;

int main(){
    int i;
    int a1,a2,a3,a4;
    scanf("%d",&k);
    scanf("%d%d%d",&n1,&n2,&n3);
    scanf("%d%d%d",&t1,&t2,&t3);
    for (i=0;i<n1;++i)
        wash.add(0);
    for (i=0;i<n2;++i)
        dry.add(0);
    for (i=0;i<n3;++i)
        fold.add(0);
    a4=0;
    for (;k;--k){
        a1=wash.pop();
        a2=dry.pop()-t1;
        a3=fold.pop()-t1-t2;
        a4=a1>a2?a1:a2;
        a4=a4>a3?a4:a3;
        wash.add(a4+t1);
        dry.add(a4+t1+t2);
        fold.add(a4+t1+t2+t3);
    }
    printf("%d",a4+t1+t2+t3);
    return 0;
}