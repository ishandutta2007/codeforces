#include<bits/stdc++.h>
#define k back()
#define e size()
#define u push_back
#define v pop_back
#define o(i) sort(a[i].begin(),a[i].end(),c)
#define q(i) (s[i.k]^s[i.front()])
using namespace std;
const int N=1e6;
int n,x,y;char s[N];
vector<vector<int>>a[2],b[2];
bool c(vector<int>i,vector<int>j){return q(i)<q(j);}
int main(){
    scanf("%s",s);n=strlen(s);
    for(int i=n-1;~i;i--){
        y=(x=s[i]>'L')^1;
        a[x].u(vector<int>());
        if(a[y].e)a[x].k.swap(a[y].k),a[y].v();
        a[x].k.u(i);
    }
    printf("%d\n",a[0].e+a[1].e-1);
    for(int z=0;z<4;z++){
        vector<int>p;o(0);o(1);y=z%2;b[0]=a[0];b[1]=a[1];
        while(b[x=y].e){
            y=s[b[x].k.front()]<'R';
            reverse(b[x].k.begin(), b[x].k.end());
            for(auto i:b[x].k)p.u(i);
            b[x].v();
        }
        if(p.e==n){for(auto i:p)printf("%d ",i+1);break;}
        if (z==1)for(x=0,y=1;x<2;x++,y--)for(auto &i:a[x])
            if (!i.k)i.v(),a[y].k.u(0),i.swap(a[y].k);
    }
}