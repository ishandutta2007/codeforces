#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
string a;

int fact[10];

int facs[4] = {2, 3, 5, 7};
int fcnt[10];
vector<int> digs;

void proc(int arg, int sign){
    for(int i=0; i<4; i++)
        while(arg % facs[i] == 0){
            arg /= facs[i];
            fcnt[i] += sign;
        }
}

int main(){
    fact[0] = 1;
    for(int i=1; i<=9; i++)
        fact[i] = i * fact[i-1];

    cin >> N >> a;
    for(char c : a){
        int dig = c - '0';
        if(dig == 0) continue;
        proc(fact[dig], 1);
    }

    for(int i=3; i>=0; i--)
        while(fcnt[i]){
            digs.push_back(facs[i]);
            proc(fact[facs[i]], -1);
        }

    sort(digs.begin(), digs.end(), greater<int>());
    for(int d : digs)
        cout << d;
    cout << endl;
}