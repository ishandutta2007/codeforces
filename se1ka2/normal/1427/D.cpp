#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    int c[60];
    for(int i = 0; i < n; i++) cin >> c[i];
    bool increase = true;
    vector<int> w[100005];
    for(int i = 2; i <= n; i++){
        bool left = true;
        for(int j = 0; j < n; j++){
            if(c[j] == i){
                left = true;
                break;
            }
            if(c[j] == 1){
                left = false;
                break;
            }
        }
        vector<int> v;
        if(increase){
            if(left){
                int t = 0;
                for(int j = 0; j < n; j++){
                    if(c[j] == i){
                        v.push_back(t);
                        v.push_back(1);
                        t = 0;
                    }
                    else if(c[j] == i - 1){
                        v.push_back(t + 1);
                        t = 0;
                    }
                    else t++;
                }
                if(t) v.push_back(t);
            }
            else{
                int t = 0;
                for(int j = 0; j < n; j++){
                    if(c[j] == 1){
                        v.push_back(t);
                    }
                    if(c[j] < i){
                        v.push_back(1);
                        t = 0;
                    }
                    else if(c[j] == i){
                        v.push_back(t + 1);
                        t = 0;
                    }
                    else t++;
                }
                if(t) v.push_back(t);
                increase = false;
            }
        }
        else{
            if(left){
                int t = 0;
                for(int j = 0; j < n; j++){
                    if(c[j] == i - 1){
                        v.push_back(t);
                    }
                    if(c[j] < i){
                        v.push_back(1);
                        t = 0;
                    }
                    else if(c[j] == i){
                        v.push_back(t);
                        t = 1;
                    }
                    else t++;
                }
                if(t) v.push_back(t);
                increase = true;
            }
            else{
                int t = 0;
                for(int j = 0; j < n; j++){
                    if(c[j] == i - 1){
                        v.push_back(t);
                        t = 1;
                    }
                    else if(c[j] == i){
                        v.push_back(t);
                        v.push_back(1);
                        t = 0;
                    }
                    else t++;
                }
                if(t) v.push_back(t);
            }
        }
        int d[60];
        int l = n;
        int j = 0;
        reverse(v.begin(), v.end());
        for(int t : v){
            if(t == 0) continue;
            w[i].push_back(t);
            l -= t;
            for(int k = 0; k < t; k++) d[j + k] = c[l + k];
            j += t;
        }
        swap(c, d);
    }
    if(!increase){
        for(int i = 0; i < n; i++) w[n + 1].push_back(1);
        n++;
    }
    cout << n - 1 << endl;
    for(int i = 2; i <= n; i++){
        reverse(w[i].begin(), w[i].end());
        cout << (int)w[i].size() << " ";
        for(int t : w[i]) cout << t << " ";
        cout << endl;
    }
}