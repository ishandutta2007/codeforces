#include <iostream>
using namespace std;

string s;
int R;

bool simula(int b){
    int hi = 0;
    int wh = 0;
    for(int i=0; i+R<s.length(); i++){
        if(s[i] == 'L') wh = max(b+1, wh-1);
        else wh++;
        hi = max(hi, wh);
    }
    return wh+R > hi;
}


int main(){
    cin >> s;
    if(s.back() == 'L')
        for(int i=0; i<s.length(); i++)
            s[i] = 'L' + 'R' - s[i];

    while(R < s.length() && s[s.length()-1-R] == 'R') R++;

    if(simula(-0x7fffffff)){ cout << 1 << endl; return 0; }

    int ans = 0;
    int lo = 1, hi = 1000000;
    while(lo <= hi){
        int mi = (lo + hi)/2;        
        if(simula(-mi)) ans = -mi, lo = mi+1;
        else hi = mi-1;
    }

    cout << -ans << endl;
}