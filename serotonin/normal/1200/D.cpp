#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2005;

char s[sz][sz];
int c[sz][2], r[sz][2];
int dc[sz][sz], dr[sz][sz];

int main()
{
    int n,k;
    cin >> n >> k;
    for(int i=0; i<n; i++) scanf("%s", s[i]);

    int ready=0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(s[i][j]=='B') {
                r[i][0]=j+1;
                break;
            }
        }
        for(int j=n-1; j>=0; j--) {
            if(s[i][j]=='B') {
                r[i][1]=j+1;
                break;
            }
        }
        if(!r[i][0]) ready++;
        r[i][0]--, r[i][1]--;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(s[j][i]=='B') {
                c[i][0]=j+1;
                break;
            }
        }
        for(int j=n-1; j>=0; j--) {
            if(s[j][i]=='B') {
                c[i][1]=j+1;
                break;
            }
        }
        if(!c[i][0]) ready++;
        c[i][0]--, c[i][1]--;
    }

    for(int i=0; i<=n-k; i++) {
        for(int j=0; j<=n-k; j++) {
            if(j) {
                dc[i][j]=dc[i][j-1];
                if(i<=c[j-1][0] && c[j-1][1]<=i+k-1) {
                    dc[i][j]--;
                }
                if(i<=c[j+k-1][0] && c[j+k-1][1]<=i+k-1) {
                    dc[i][j]++;
                }
            }
            else {
                for(int w=0; w<k; w++) {
                    if(i<=c[w][0] && c[w][1]<=i+k-1) {
                        dc[i][0]++;
                    }
                }
            }
        }
    }

    for(int i=0; i<=n-k; i++) {
        for(int j=0; j<=n-k; j++) {
            if(j) {
                dr[j][i]=dr[j-1][i];
                if(i<=r[j-1][0] && r[j-1][1]<=i+k-1) {
                    dr[j][i]--;
                }
                if(i<=r[j+k-1][0] && r[j+k-1][1]<=i+k-1) {
                    dr[j][i]++;
                }
            }
            else {
                for(int w=0; w<k; w++) {
                    if(i<=r[w][0] && r[w][1]<=i+k-1) {
                        dr[0][i]++;
                    }
                }
            }
        }
    }

    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ans=max(ans, dc[i][j]+dr[i][j]);
        }
    }

    cout << ans+ready;
}