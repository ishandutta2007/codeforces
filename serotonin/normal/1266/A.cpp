#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

char a[sz];

int main()
{
    int n;
    cin >> n;
    while(n--) {
        scanf("%s", a);
        bool zero=0;
        int tot=0, even=0;
        for(int i=0; a[i]; i++) {
            int x=a[i]-'0';
            if(!x) zero=1;
            if(x%2==0) even++;
            tot+=x;
        }
        if(zero && even>1 && tot%3==0) puts("red");
        else puts("cyan");
    }
}