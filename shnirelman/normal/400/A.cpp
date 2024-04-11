#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> b;
    for(int i = 1; i <= 12; i++)
        if(12 % i == 0)b.push_back(i);

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        int cnt = 0;
        vector<bool> bis(b.size());
        for(int j = 0; j < b.size(); j++){
            bool flag = false;
            for(int l = 0; l < b[j] && !flag; l++){
                flag = true;
                for(int k = l; k < 12; k += b[j])
                    if(k < 12)if(s[k] != 'X')flag = false;
            }


            bis[j] = flag;
            cnt += flag;


        }
        cout << cnt <<' ';
        for(int j = b.size() - 1; j >= 0; j--)
            if(bis[j])cout << 12 / b[j] << 'x' << b[j] << ' ';
        cout << endl;
    }

}