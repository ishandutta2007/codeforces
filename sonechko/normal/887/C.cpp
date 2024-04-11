#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ss second
#define ff first
const int MOD = 1000000007;
#define mod %MOD
#define pb push_back
#define ld long double
const int N = 1e6 + 11;
const int MAX = 1e8;

int a[100];

bool g(int l1, int l2, int l3, int l4, int l5, int l6, int l7, int l8, int l9, int l10, int l11, int l12, int l13, int l14, int l15, int l16, int l17, int l18, int l19, int l20, int l21, int l22, int l23, int l24)
{
    if (a[l1]==a[l2]&&a[l1]==a[l3]&&a[l1]==a[l4]&&
        a[l5]==a[l6]&&a[l5]==a[l7]&&a[l5]==a[l8]&&
        a[l9]==a[l10]&&a[l9]==a[l11]&&a[l9]==a[l12]&&
        a[l13]==a[l14]&&a[l13]==a[l15]&&a[l13]==a[l16]&&
        a[l17]==a[l18]&&a[l17]==a[l19]&&a[l17]==a[l20]&&
        a[l21]==a[l22]&&a[l21]==a[l23]&&a[l21]==a[l24])
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i=1; i<=24; i++)
        cin>>a[i];
    if (g(1,2,3,4,9,10,11,12,5,6,15,16,13,14,23,24,21,22,19,20,17,18,7,8)||
        g(1,2,3,4,9,10,11,12,5,6,19,20,17,18,23,24,21,22,15,16,13,14,7,8)||
        g(13,14,15,16,17,18,19,20,7,5,4,2,3,1,21,23,22,24,12,10,11,9,8,6)||
        g(13,14,15,16,17,18,19,20,7,5,12,10,11,9,21,23,22,24,4,2,3,1,8,6)||
        g(21,22,23,24,5,6,7,8,18,20,3,4,1,2,16,14,15,13,10,9,12,11,17,19)||
        g(21,22,23,24,5,6,7,8,18,20,10,9,12,11,16,14,15,13,3,4,1,2,17,19))
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}