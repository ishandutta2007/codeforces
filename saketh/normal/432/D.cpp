#include <iostream>
using namespace std;

const int MAXL = 100005;

int N;
string A;
int succ[MAXL], occ[MAXL];
bool match[MAXL];

int main(){
    cin >> A; A = A;
    N = A.length();

    succ[0] = -1;
    int j = -1;

    for(int i=1; i<N; i++){
        while(j>=0 && A[j+1]!=A[i]) j=succ[j];
        if(A[j+1]==A[i]) j++;
        succ[i] = j;
    }

    for(int i=0; i<N; i++)
        occ[succ[i]+1]++;

    for(int i=N-1; i>0; i--)
        occ[succ[i]+1] += occ[i+1];

    int p = 0;
    for(int i=N-1; i>=0; i=succ[i]){
        match[i+1] = true;
        p++;
    }

    cout << p << "\n";
    for(int i=1; i<=N; i++)
        if(match[i]) cout << i << " " << occ[i]+1 << "\n";
    cout.flush();
    return 0;
}