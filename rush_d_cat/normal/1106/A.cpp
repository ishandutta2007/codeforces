#include <iostream>
#include <algorithm>
using namespace std;
const int N = 500 + 10;
typedef long long LL;

int n; char s[N][N];
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    int c=0;
    for(int i=2;i<n;i++){
        for(int j=2;j<n;j++){
            if(s[i][j]=='X' && s[i-1][j-1] == 'X' && s[i-1][j+1]=='X' && s[i+1][j+1] == 'X' && s[i+1][j-1] == 'X') c++;
        }
    }
    cout << c << endl;
}