#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

int a[sz];

int main()
{
    int q;
    cin >> q;
    int l=-1,r=1,id;
    char ch;
    q--;
    scanf("\n%c %d", &ch, &id);
    a[id]=0;
    while(q--) {
        scanf("\n%c %d", &ch, &id);
        if(ch=='L') {
            a[id]=l;
            l--;
        }
        else if(ch=='R') {
            a[id]=r;
            r++;
        }
        else {
            int pos=a[id];
            int x=pos-l-1;
            int y=r-pos-1;
            printf("%d\n", min(x,y));
        }
    }
}