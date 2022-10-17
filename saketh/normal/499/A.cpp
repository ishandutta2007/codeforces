#include <iostream>
#include <algorithm>
using namespace std;

int N, X, o, a;
pair<int, int> b[50];

int main(){
    cin >> N >> X;
    for(int i=0; i<N; i++)
        cin >> b[i].first >> b[i].second;

    sort(b, b+N);

    for(int i=0; i<N; i++){
        a += b[i].second - b[i].first + 1;
        int gap = b[i].first - o - 1;
        a += gap - gap/X*X;
        o = b[i].second;
    }
    
    cout << a << endl;
    return 0;
}