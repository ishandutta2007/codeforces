#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1e6 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    char koz;
    cin>>koz;
    char ch1,ko1,ch2,ko2;
    cin>>ch1>>ko1>>ch2>>ko2;
    if (ko1==koz&&ko2!=koz) {cout<<"YES"<<endl; return 0;}
    if (ko1!=ko2) {cout<<"NO"<<endl; return 0;}
    int p1=0,p2=0;
    if (ch1=='6') p1=1;
    if (ch1=='7') p1=2;
    if (ch1=='8') p1=3;
    if (ch1=='9') p1=4;
    if (ch1=='T') p1=5;
    if (ch1=='J') p1=6;
    if (ch1=='Q') p1=7;
    if (ch1=='K') p1=8;
    if (ch1=='A') p1=9;

    if (ch2=='6') p2=1;
    if (ch2=='7') p2=2;
    if (ch2=='8') p2=3;
    if (ch2=='9') p2=4;
    if (ch2=='T') p2=5;
    if (ch2=='J') p2=6;
    if (ch2=='Q') p2=7;
    if (ch2=='K') p2=8;
    if (ch2=='A') p2=9;

    if (p1>p2) cout<<"YES"<<endl; else cout<<"NO"<<endl;
}