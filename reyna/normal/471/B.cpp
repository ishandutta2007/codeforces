#include <iostream>
#include <algorithm>
using namespace std;
int arr[2001][3];
pair<int,int> Seq[2001];
int N[2001];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> Seq[i].first;
        Seq[i].second = i+1;
        N[Seq[i].first]++;
    }
    sort(Seq,Seq+n);
    long long counter = 1;
    for(int i = 0; i <= 2000;i++){
        counter *= max(1,N[i]);
        if(counter >= 3){
            break;
        }
        if(i == 2000){
            cout << "NO" << endl;
            return 0;
        }
    }
    bool k = false;
    counter = 0;
    int last = -1;
    int l = -1000000;
    for(int i = 0; i < n;i++){
        if(N[Seq[i].first] == 2 && Seq[i].first != last){
            arr[i][(counter)%3] = Seq[i].second;
            arr[i][(counter+1)%3] = Seq[i+1].second;
            arr[i][(counter+2)%3] = Seq[i].second;
            arr[i+1][(counter)%3] = Seq[i+1].second;
            arr[i+1][(counter+1)%3] = Seq[i].second;
            arr[i+1][(counter+2)%3] = Seq[i+1].second;
            last = Seq[i].first;
            counter++;
        }else if(!k && N[Seq[i].first] > 2){
            arr[i][0] = Seq[i].second;
            arr[i][1] = Seq[i+1].second;
            arr[i][2] = Seq[i+2].second;
            arr[i+1][0] = Seq[i+1].second;
            arr[i+1][1] = Seq[i+2].second;
            arr[i+1][2] = Seq[i+1].second;
            arr[i+2][0] = Seq[i+2].second;
            arr[i+2][1] = Seq[i].second;
            arr[i+2][2] = Seq[i].second;
            l = i;
            k = true;
        }else if(Seq[i].first != last && i-l>2){
            arr[i][0] = Seq[i].second;
            arr[i][1] = Seq[i].second;
            arr[i][2] = Seq[i].second;
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < n;j++){
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}