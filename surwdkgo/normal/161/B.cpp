#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
struct Obj{
    int pri, typ, ind;
    Obj(){}
    Obj(int p, int t, int i): pri(p), typ(t), ind(i){}   
}ite[1010];
vector<int> cat[1010];
bool cmp(Obj a, Obj b){
    return a.pri>b.pri;   
}
int n,k, st, sc, pc;
long long ans;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        cat[i].clear();
        scanf("%d%d",&ite[i].pri, &ite[i].typ);
        ans+=ite[i].pri*2;
        ite[i].ind = i;
        if(ite[i].typ==1)st++;
    }
    std::sort(ite, ite+n, cmp);
    
    pc = st;
    for(int i=0;i<n;i++){
        if(ite[i].typ==1 && sc<k){
            cat[sc].push_back(i);
            if(sc<k-1)ans-=ite[i].pri;
            sc++;
        }else{
            if(ite[i].typ==2 && pc<k){
                cat[pc].push_back(i);
                pc++;                    
            }else cat[k-1].push_back(i);   
        }
    }
    if(st>=k)ans-=ite[n-1].pri;
    
    printf("%I64d.%d\n", ans/2, ans%2==1?5:0);
    for(int i=0;i<k;i++){
        printf("%d", cat[i].size());
        for(int j=0;j<cat[i].size();j++){
            printf(" %d", ite[cat[i][j]].ind+1);   
        }
        puts("");
    }
    scanf(" ");
}