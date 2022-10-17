#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<char> v;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        char c;
        cin >> c;
        if(c >= 'a') c = c - 'a' + 'A';
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    cout << (unique(v.begin(), v.end()) - v.begin() == 26 ? "YES" : "NO") << endl;
}