#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int a[N],b[N];
main(){
        string s;
        vector<int>ans;
        cin>>s;
        int i=0, j = s.size()-1;
        while(i < j){
            while(j >=0 && s[j] == '(') j--;
            while(i <s.size() && s[i] == ')') i++;
            if(i > j) break;

            ans.push_back(i);
            ans.push_back(j);
            i++;
            j--;


        }
        if(ans.size()){
            cout<<1<<endl<<ans.size()<<endl;
            sort(ans.begin(),ans.end());
            for(int x:ans)
                cout<<x+1<<" ";
            cout<<endl;
        }
        else cout<<0<<endl;
}