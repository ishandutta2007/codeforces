#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int MAXN = 100005;

string s;
int p[4][MAXN];
int N, X, Y;

int main(){
    cin >> s;
    scanf("%d", &N);

    for(int i=1; i<=s.length(); i++){
        char c = s[i-1];
        p[3][i] = p[3][i-1] + (c<'x' || c>'z');
        for(char j='x'; j<='z'; j++)
            p[j-'x'][i] = p[j-'x'][i-1] + (c==j);
    }

    for(int i=0; i<N; i++){
        scanf("%d %d", &X, &Y);
        int x = p[0][Y] - p[0][X-1];
        int y = p[1][Y] - p[1][X-1];
        int z = p[2][Y] - p[2][X-1];
        int o = p[3][Y] - p[3][X-1];

        if(x+y+z+o < 3) printf("YES\n");
        else if(o > 0) printf("NO\n");
        else{
            int low = min(x, min(y, z));
            int high = max(x, max(y, z));
            int dif = high - low;
            if(dif <= 1) printf("YES\n");
            else printf("NO\n");
        }
    }
    
    return 0;
}