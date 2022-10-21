#include <bits/stdc++.h>
using namespace std;

string str;
vector<int> G[200500];
queue<int> que0;
queue<int> que1;
int cnt = 0;
int fre[2];

int main() {
    getline(cin, str);
    for(int i = 0; i < str.length(); i++) fre[str[i]-'0']++;
//    if(fre[1] >= fre[0]) return !printf("-1");
    int cnt0 = fre[0], cnt1 = fre[1];
    for(int i = 0; i < cnt0-cnt1; i++){
        que0.push(i);
    }
    for(int i = 0; i < str.length(); i++){
        int num = str[i] - '0';
        if(num == 0){
            if(que0.empty()) return !printf("-1");
            int index = que0.front();
            que0.pop();
            G[index].push_back(i);
            que1.push(index);
        }
        else{
            if(que1.empty()) return !printf("-1");
            int index = que1.front();
            que1.pop();
            G[index].push_back(i);
            que0.push(index);
        }
    }
    cout << (cnt0-cnt1) << endl;
    for(int i = 0; i < cnt0-cnt1; i++){
        cout << G[i].size() << " ";
        for(int num : G[i]) cout << num+1 << " ";
        cout << endl;
    }


}