#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ss second
#define ff first
#define ld long double
#define mp make_pair

const int N = 2e5 + 11;



int main()
{
         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
         int a,b,c;
         cin>>a>>b>>c;
         if (a==1||b==1||c==1) {cout<<"YES"<<endl; return 0;}
         if (a==2&&b==2) {cout<<"YES"<<endl; return 0;}
         if (a==2&&c==2) {cout<<"YES"<<endl; return 0;}
         if (b==2&&c==2) {cout<<"YES"<<endl; return 0;}
         if (a==3&&b==3&&c==3) {cout<<"YES"<<endl; return 0;}
         if (a==2&&b==4&&c==4) {cout<<"YES"<<endl; return 0;}
         if (a==4&&b==2&&c==4) {cout<<"YES"<<endl; return 0;}
         if (a==4&&b==4&&c==2) {cout<<"YES"<<endl; return 0;}
         cout<<"NO"<<endl;
}