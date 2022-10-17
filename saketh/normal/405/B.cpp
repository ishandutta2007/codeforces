#include <iostream>
using namespace std;

int N, A;
string s;
char last = 'L';
int lidx = -1;

int main(){
    cin >> N >> s;
    
    for(int i=0; i<N; i++){
        if(s[i] == '.') continue;
        if(s[i] == 'R') A += i - lidx - 1;
        else if(last == 'R') A += (i - lidx - 1)%2;
            
        lidx = i;
        last = s[i];
    }

    if(last == 'L') A += N - 1 - lidx;
    cout << A << endl;
    return 0;
}