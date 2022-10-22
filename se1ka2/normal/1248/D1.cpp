#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = -1;
    int ansi, ansj;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            swap(s[i], s[j]);
            int les = 0;
            int now = 0;
            for(int k = 0; k < n; k++){
                if(s[k] == '(') now++;
                else now--;
                les = min(les, now);
            }
            if(now != 0){
                cout << 0 << endl;
                cout << "1 1" << endl;
                return 0;
            }
            int cd = 0;
            for(int k = 0; k < n; k++){
                if(s[k] == '(') now++;
                else now--;
                if(now == les) cd++;
            }
            if(cd > ans){
                ans = cd;
                ansi = i, ansj = j;
            }
            swap(s[i], s[j]);
        }
    }
    cout << ans << endl;
    cout << ansi + 1 << " " << ansj + 1 << endl;
}