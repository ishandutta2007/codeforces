#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5;

char s[sz];
int a[10];

int main()
{
    int n;
    cin >> n;
    scanf("%s", s);
    for(int i=0; s[i]; i++) {
        if(s[i]=='L') {
            for(int j=0; j<10; j++) {
                if(!a[j]) {
                    a[j]=1;
                    break;
                }
            }
        }
        else if(s[i]=='R') {
            for(int j=9; j>=0; j--) {
                if(!a[j]) {
                    a[j]=1;
                    break;
                }
            }
        }
        else {
            a[s[i]-'0']=0;
        }
    }

    for(int i=0; i<10; i++) printf("%d", a[i]);
}