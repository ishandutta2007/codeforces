#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N, A, s[128];

int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> s[i];
    sort(s, s+N);

    for(int i=0; i<N; i++)
        A += i+1>A*(s[i]+1);

    cout << A << endl;
    return 0;
}