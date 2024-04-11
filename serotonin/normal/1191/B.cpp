#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int main()
{
    char s[10];
    vector <int> a;
    for(int i=0; i<3; i++) {
        scanf("%s", s);
        int d=s[0]-'0';
        if(s[1]=='p') a.push_back(100+d);
        else if(s[1]=='s') a.push_back(200+d);
        else a.push_back(300+d);
    }
    sort(a.begin(), a.end());

    if(a[0]==a[1] && a[1]==a[2]) puts("0");
    else if(a[1]==a[0]+1 && a[2]==a[1]+1) puts("0");
    else if(a[0]==a[1] || a[1]==a[2]) puts("1");
    else if(a[1]==a[0]+1 || a[2]==a[1]+1) puts("1");
    else if(a[1]==a[0]+2 || a[2]==a[1]+2) puts("1");
    else puts("2");
}