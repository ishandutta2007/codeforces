#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5,p=998244353;

char s[sz];

int main()
{
    ll i,j,k=1;
    cin >> s;
    ll l=strlen(s);
    j=l/2;
    if(l%2==0) j--;
    printf("%c", s[j]);
    for(i=1; k<l; i++) {
        printf("%c", s[j+i]);
        k++;
        if(k==l) break;
        printf("%c", s[j-i]);
        k++;
    }
}