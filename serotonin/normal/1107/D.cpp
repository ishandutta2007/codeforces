#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5555, inf=2e9+5;

bool s[sz][sz];
char now[sz];
int a[sz];

void spread(int i, char c, int j)
{
    int d;
    if(c>='0' && c<='9') d=c-'0';
    else d=c-'A'+10;
    int x=1;
    for(int k=j*4+3; k>=j*4; k--) {
        if(x&d) s[i][k]=1;
        else s[i][k]=0;
        x<<=1;
    }
}

int main()
{
    int n,k,i,j;
    cin >> n;
    for(i=0; i<n; i++) {
        scanf("%s", now);
        for(j=0; j<n/4; j++) {
            spread(i,now[j],j);
        }
    }
    set <int> ans;
    for(i=1; i<=n; i++) if(n%i==0) ans.insert(i);

    for(i=0; i<n; i++) {
        a[0]=0;
        for(j=0; j<n; j++) a[j+1]=a[j]+s[i][j];
        set <int> :: iterator it;
        vector <int> screw;
        for(it=ans.begin(); it!=ans.end(); it++) {
            int x=*it;
            for(j=x; j<=n; j+=x) {
                if(a[j]-a[j-x]!=x && a[j]-a[j-x]!=0) break;
            }
            if(j<=n) screw.push_back(x);
        }
        for(j=0; j<screw.size(); j++) ans.erase(screw[j]);
    }

    for(i=0; i<n; i++) {
        a[0]=0;
        for(j=0; j<n; j++) a[j+1]=a[j]+s[j][i];
        set <int> :: iterator it;
        vector <int> screw;
        for(it=ans.begin(); it!=ans.end(); it++) {
            int x=*it;
            for(j=x; j<=n; j+=x) {
                if(a[j]-a[j-x]!=x && a[j]-a[j-x]!=0) break;
            }
            if(j<=n) screw.push_back(x);
        }
        for(j=0; j<screw.size(); j++) ans.erase(screw[j]);
    }
    printf("%d\n", *(ans.rbegin()));
}