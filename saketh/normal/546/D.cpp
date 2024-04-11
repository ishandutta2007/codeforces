#include <iostream>
#include <cstdio>
using namespace std;

const int MAXV = 5000000;

int T, A, B;
int np[MAXV+1];
long long fp[MAXV+1];

int main(){
    for(int p=2; p<=MAXV; p++)
        if(np[p]) continue;
        else for(int q=p; q<=MAXV; q+=p)
            np[q] = 1 + np[q/p];

    for(int f=2; f<=MAXV; f++)
        fp[f] = np[f] + fp[f-1];

    ios_base::sync_with_stdio(false);
    for(cin >> T; T; T--){
        cin >> A >> B;
        printf("%d\n", fp[A] - fp[B]);
    }
}