#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
typedef __int64 ll;
ll m,n,res=0;
set<int> s;
ll f(ll m)
{
    if(m==1) return 1;
    ll tmp=1,res=0;
    while(tmp<m){tmp*=7;res++;}
    return res;
}
int main()
{
    cin>>m>>n;
    ll m_=f(m),n_=f(n);
    if(m_+n_>7)
        cout<<0<<endl;
    else{
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int i_=i,j_=j;
                for(int k=1;k<=m_;k++){
                    s.insert(i_%7);
                    i_/=7;
                }
                for(int k=1;k<=n_;k++){
                    s.insert(j_%7);
                    j_/=7;
                }
                if(s.size()==(m_+n_)) res++;
                s.clear();
            }
        }
        cout<<res<<endl;
    }
    return 0;
}