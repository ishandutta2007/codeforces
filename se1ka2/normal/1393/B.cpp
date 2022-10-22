#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int b[100005]{0};
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        b[a]++;
    }
    set<int> st2, st4, st6, st8;
    for(int i = 1; i <= 100000; i++){
        if(b[i] >= 8) st8.insert(i);
        else if(b[i] >= 6) st6.insert(i);
        else if(b[i] >= 4) st4.insert(i);
        else if(b[i] >= 2) st2.insert(i);
    }
    int q;
    cin >> q;
    while(q--){
        char c;
        int x;
        cin >> c >> x;
        if(c == '+'){
            b[x]++;
            if(b[x] == 8){
                st8.insert(x);
                st6.erase(x);
            }
            if(b[x] == 6){
                st6.insert(x);
                st4.erase(x);
            }
            if(b[x] == 4){
                st4.insert(x);
                st2.erase(x);
            }
            if(b[x] == 2){
                st2.insert(x);
            }
        }
        else{
            b[x]--;
            if(b[x] == 7){
                st8.erase(x);
                st6.insert(x);
            }
            if(b[x] == 5){
                st6.erase(x);
                st4.insert(x);
            }
            if(b[x] == 3){
                st4.erase(x);
                st2.insert(x);
            }
            if(b[x] == 1){
                st2.erase(x);
            }
        }
        if(!st8.empty() ||
           (!st6.empty() && (!st4.empty() || !st2.empty() || (int)st6.size() >= 2)) ||
           (!st4.empty() && ((int)st2.size() >= 2 || (int)st4.size() >= 2))){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}