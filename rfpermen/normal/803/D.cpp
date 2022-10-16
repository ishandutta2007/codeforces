# include <bits/stdc++.h>
 
using namespace std;
 
int R;
string s;
vector<int> v;
 
bool bisa(int C){
    int row=1;
    int cur=0;
    int last;
 
    for(int i=0; i<v.size(); ){
        if(v[i] > C) return false;
        if(cur + v[i] <= C){
            cur+=v[i];
            i++;
        }
        else{
            row++;
            cur=0;
        }
        last=i;
    }
 
    if(row <= R) return true;
    return false;
}
 
int main(){
 
    cin >> R; getchar();
    getline(cin,s);
 
    int last=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='-' || s[i]==' '){
            v.push_back(i-last+1);
            last=i+1;
        }
    }
    v.push_back(s.size()-last);
 
    int lo=1, hi=1000000, ans;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(bisa(mid)){
            hi=mid-1;
            ans=mid;
        }
        else lo=mid+1;
    }
 
    cout << ans << endl;
    return 0;
}