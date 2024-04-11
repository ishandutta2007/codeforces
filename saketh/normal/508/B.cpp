#include <iostream>
using namespace std;

int N;
string s;

int main(){
    cin >> s;
    N = s.length();

    int e = s[N-1] - '0';
    int g = -1, l = -1;

    for(int i=0; i+1<N; i++){
        int h = s[i] - '0';
        if(h%2) continue;

        if(h > e) g = i;
        else if(l == -1) l = i;
    }

    if(l != -1){
        swap(s[l], s[N-1]);
        cout << s << endl;
    }
    else if(g != -1){
        swap(s[g], s[N-1]);
        cout << s << endl;
    }
    else{
        cout << -1 << endl;
    }
}