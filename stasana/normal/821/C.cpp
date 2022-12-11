#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
    int n;
    int res = 0;
    string s;
    vector<int> stek;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n+n; ++i){
        cin >> s;
        if(s == "add"){
            int qwer;
            cin >> qwer;
            stek.push_back(qwer);
        }
        if(s == "remove"){
            ++cnt;
            if(stek.size() > 0 && stek.back() == cnt){
                stek.pop_back();
            }else if(stek.size() > 0){
                vector<int> qwer;
                stek = qwer;
                ++res;
            }
        }
    }
    cout << res;
    return 0;
}