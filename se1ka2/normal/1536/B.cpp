#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        set<string> st;
        for(int l = 1; l <= 3; l++){
            for(int i = 0; i <= n - l; i++){
                st.insert(s.substr(i, l));
            }
        }
        bool f = false;
        for(int i = 0; i < 26; i++){
            string u = "";
            u += char('a' + i);
            if(st.find(u) == st.end()){
                cout << u << endl;
                goto end;
            }
        }
        if(f) continue;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                string u = "";
                u += char('a' + i);
                u += char('a' + j);
                if(st.find(u) == st.end()){
                    cout << u << endl;
                    goto end;
                }
            }
        }
        if(f) continue;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                for(int k = 0; k < 26; k++){
                    string u = "";
                    u += char('a' + i);
                    u += char('a' + j);
                    u += char('a' + k);
                    if(st.find(u) == st.end()){
                        cout << u << endl;
                        goto end;
                    }
                }
            }
        }
end:
        cout << "";
    }
}