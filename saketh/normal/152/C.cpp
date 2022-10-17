#include<iostream>
#define MOD 1000000007
using namespace std;

int N, M;
long long A;
char t;
bool s[105][27];
int tot[105];

int main(){
    cin >> N >> M;
    for(int a=0; a<105; a++)
        for(int b=0; b<27; b++)
            s[a][b] = false;
    for(int n=0; n<N; n++)
        for(int m=0; m<M; m++){
            cin >> t;
            if(!s[m][t-'A'])
                tot[m]++;
            s[m][t-'A'] = true;
        }
    for(A=1, t=0; t<M; t++)
        A = (A*tot[t])%MOD;
    cout << A << endl;
}