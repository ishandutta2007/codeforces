#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<pair<int, string> > s(n, make_pair(0, ""));
    for(int i = 0; i < n; i++){
        cin >> s[i].second;
        s[i].first = s[i].second.length();
    }
    
    sort(s.begin(), s.end());
    
    for(int i = 1; i < n; i++)
        if(s[i].second.find(s[i-1].second) == size_t(-1)){
            cout << "NO";
            return 0;
        }
        
    cout << "YES" << endl;
    for(int i = 0; i < n; i++)cout << s[i].second << endl;
}