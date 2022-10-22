#include <algorithm>
#include <iostream>
using namespace std;

int a[6] = {4, 8, 15, 16, 23, 42};

int main()
{
    int s[4];
    for(int i = 0; i < 4; i++){
        cout << "? " << i + 1 << " " << i + 2 << endl;
        fflush(stdout);
        cin >> s[i];
    }
    int per[6] = {0, 1, 2, 3, 4, 5};
    do{
        bool f = true;
        for(int i = 0; i < 4; i++){
            if(a[per[i]] * a[per[i + 1]] != s[i]){
                f = false;
                break;
            }
        }
        if(f){
            cout << "! ";
            for(int i = 0; i < 6; i++) cout << a[per[i]] << " ";
            cout << endl;
            break;
        }
    }while(next_permutation(a, a + 6));
}