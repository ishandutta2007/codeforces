#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

int n;
char s[sz];

void big()
{
    int l=1, h=1;
    vector <int> incs;
    incs.push_back(1);
    for(int i=0; i<n-1; i++) {
        if(s[i]=='<') incs.push_back(++h);
        else incs.push_back(--l);
    }

    for(int x : incs) printf("%d ", x+1-l);
    puts("");
}

void smol()
{
    int l=1;
    vector <int> incs;
    incs.push_back(1);
    for(int i=0; i<n-1; i++) {
        if(s[i]=='>') incs.push_back(--l);
        else {
            int k=0;
            for(int j=i; j<n-1; j++) {
                if(s[j]=='<') k++;
                else break;
            }
            incs[i]-=k;
            l=incs[i];
            for(int j=0; j<k; j++) incs.push_back(l+j+1);
            i+=k-1;
        }
    }

    for(int x : incs) printf("%d ", x+1-l);
    puts("");
}

int main()
{
    int q;
    cin >> q;
    while(q--) {
        scanf("%d %s", &n, s);

        smol();

        big();
    }
}