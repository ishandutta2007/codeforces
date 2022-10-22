#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    //ofstream fout("output.txt");
    //ifstream fin("input.txt");

    int a, b, f, k;
    cin >> a >> b >> f >> k;

    int ans = 0;
    int c = b;
    for(int i = 0; i < k; i++){
        if(c < f){
            cout << -1;
            return 0;
        }

        if(i == k - 1){
            if(c >= a)break;
            ans++;
            if(b < a - f){
                cout << -1;
                return 0;
            }
        }
        else{
            if(c < a + a - f){
                ans++;
                c = b - a * 2 + f * 2;
                if(c < 0){
                    cout << -1;
                    return 0;
                }
            }
            else c -= a * 2 - f;


            if(i == k - 2){
                if(c >= f)break;
                ans++;
                if(b < f){
                    cout << -1;
                    return 0;
                }
            }
            else{
                if(c < f * 2){
                    ans++;
                    c = b - f;
                    if(c < 0){
                        cout << -1;
                        return 0;
                    }
                }
                else c -= f;
            }
        }

        i++;

        //if(i >= k)break;
        //cout << i << ' ' << ans << ' ' << c << endl;
    }

    cout << ans;
}