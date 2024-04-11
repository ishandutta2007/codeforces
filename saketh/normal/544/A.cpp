#include <iostream>
#include <vector>
using namespace std;

int K;
string q;

vector<string> ans;
bool seen[256];

int main(){
    cin >> K >> q;

    int i=-1;
    for(int j=0; j<q.size(); j++){
        if(seen[q[j]]) continue;
        if(i != -1){
            ans.push_back(q.substr(i, j-i));
        }
        seen[q[j]] = true;
        i = j;
        if(ans.size() == K-1) break;
    }

    ans.push_back(q.substr(i));
    if(ans.size() != K)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for(string s : ans) cout << s << endl;
    }
}