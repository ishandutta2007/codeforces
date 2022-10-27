#include<iostream>
#include<map>
#include<cstdio>
#include<stdio.h>
using namespace std;
typedef __int64 ll;
char s[100000+2];
map<char,int> st;
int main()
{
    ll n;cin>>n;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        st[s[i]]++;
    }
    int sz=st.size();
    st.clear();
    int l=1,r=1;
    int res=100000+2;
    st[s[1]]++;
    while(r<=n)
    {
        if((st.size()==sz))
        {
            res=min(res,r-l+1);
            st[s[l]]--;
            if(st[s[l]]==0) st.erase(s[l]);
            l++;
        }
        if(st.size()<sz)
        {
            if(r==n) break;
            r++;
            st[s[r]]++;
        }
    }
    cout<<res<<endl;
    return 0;
}