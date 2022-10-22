#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for(int c = 0; c < k; c++){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> vs, vt;
        bool f = true;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i]){
                f = false;
                for(int j = i + 1; j < n; j++){
                    if(s[i] == s[j]){
                        vs.push_back(j);
                        vt.push_back(i);
                        swap(t[i], s[j]);
                        f = true;
                        break;
                    }
                }
                if(!f){
                    for(int j = i + 1; j < n; j++){
                        if(s[i] == t[j]){
                            vs.push_back(i);
                            vt.push_back(i);
                            vs.push_back(i);
                            vt.push_back(j);
                            swap(t[i], s[i]);
                            swap(t[j], s[i]);
                            f = true;
                            break;
                        }
                    }
                }
                if(!f){
                    cout << "No" << endl;
                    break;
                }
            }
        }
        if(!f) continue;
        cout << "Yes" << endl;
        cout << (int)vs.size() << endl;
        for(int i = 0; i < (int)vs.size(); i++){
            cout << vs[i] + 1 << " " << vt[i] + 1 << endl;
        }
    }
}