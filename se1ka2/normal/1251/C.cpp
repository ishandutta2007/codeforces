#include <iostream>
#include <string>
using namespace std;

int odd[300005], even[300005];

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        string a;
        cin >> a;
        int o = 0, e = 0;
        int n = a.size();
        for(int i = 0; i < n; i++){
            if((a[i] - '0') % 2){
                odd[o] = a[i] - '0';
                o++;
            }
            else{
                even[e] = a[i] - '0';
                e++;
            }
        }
        odd[o] = 100;
        even[e] = 100;
        int no = 0, ne = 0;
        while(no < o || ne < e){
            if(odd[no] < even[ne]){
                cout << odd[no];
                no++;
            }
            else{
                cout << even[ne];
                ne++;
            }
        }
        cout << endl;
    }
}