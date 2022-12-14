    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        string s;
        cin>>s;
        int l=0,r=s.size()-1;
        string A="";
        string B="";
        int aa=0,bb=0,cc=0;
        for (int i=0;i<s.size();i++){
            if (s[i]=='a')aa++;
            if (s[i]=='b')bb++;
            if (s[i]=='c')cc++;
        }
        while(l<r)
        {
            if (s[l]==s[r])A+=s[l],B+=s[l],l++,r--;
            else if (l+1<r && s[l+1]==s[r])A+=s[r],B+=s[r],l+=2,r--;
            else if (l<r-1 && s[l]==s[r-1])A+=s[l],B+=s[l],l++,r-=2;
            else if (l+1<r-1 && s[l+1]==s[r-1])A+=s[l+1],B+=s[l+1],l+=2,r-=2;
            else break;
        }
        reverse(B.begin(),B.end());
        string ret=A+B;
     
        if (l<=r)
            ret=A+s[l]+B;
        int mn = s.size();
        mn/=2;
        if (aa>=mn)
        {
            ret="";
            while(aa--)ret+="a";
        }
        if (bb>=mn)
        {
            ret="";
            while(bb--)ret+="b";
        }
        if (cc>=mn)
        {
            ret="";
            while(cc--)ret+="c";
        }
        if (ret.size()>=mn)cout<<ret<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
     
    }