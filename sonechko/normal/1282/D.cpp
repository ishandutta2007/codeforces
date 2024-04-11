#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int get(string s)
{
    cout<<s<<endl;
    int x;
    cin>>x;
    if (x==0) exit(0);
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n1=get("b");
    string s="";
    for (int j=1; j<=n1; j++)
        s+="a";
    int n2=get(s);
    int n=n1+1;
    string ans=s;
    ans+="a";
    int k=n2;
    ///cout<<"!!!"<<k<<endl;
    for (int i=0; i<=n-1; i++)
    {
        ans[i]='b';
        int kk=get(ans);
        if (kk==-1) while (1==1) {}
        if (kk>k) {ans[i]='a';} else k=kk;
    }
}
/**
a a a a a a a
n - 0|1
b
n - 0|1

a b max(n1,n2)=n

aaaaaaaaaaaaa  =  k
+
abaaaaaaaaaaa  = k


aabba
**/