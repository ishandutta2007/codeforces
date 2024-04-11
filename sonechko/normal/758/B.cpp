#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
int a[N];
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif // LOCAL
    sync;
    string s;
    cin>>s;
    string t="RBYG";
    for (int i=0; i<t.size(); i++)
        for (int j=0; j<t.size(); j++)
        for (int k=0; k<t.size(); k++)
        for (int p=0; p<t.size(); p++)
            if (i!=j&&i!=k&&i!=p&&j!=k&&j!=p&&k!=p)
    {
        char ch1=t[i],ch2=t[j],ch3=t[k],ch4=t[p];
        int k1=0,k2=0,k3=0,k4=0;
        string t1="";
        for (int ij=0; ij<s.size(); ij++)
            if (ij%4==0) t1+=ch1; else
            if (ij%4==1) t1+=ch2; else
            if (ij%4==2) t1+=ch3; else t1+=ch4;
        int ans=-1;
        for (int ij=0; ij<s.size(); ij++)
            if (s[ij]=='!')
            {
                if (t1[ij]=='R') k1++; else
                if (t1[ij]=='B') k2++; else
                if (t1[ij]=='Y') k3++; else k4++;
            } else
            if (s[ij]!=t1[ij]) ans=0;
        if (ans==-1) {cout<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<endl; return 0;}
    }
}