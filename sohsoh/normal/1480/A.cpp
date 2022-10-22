/*
 * asdf
 * as
 * df
 * asdbf
 * asd
 * as
 * f
 * asddf
 * asf
 * as
 *
 * asd
 *
 * asd
 * a
 * sdf
 * as
 * fd
 * asdf
 * asd
 * f
 * asdf
 * sad
 * f
 * asdf
 * sad
 * fsadf
 * asdf
 *  
 *  as
 *  f
 *  */
#include<bits/stdc++.h>
using namespace std;
int i,t;
string s;
main()
{
	for(cin>>t;t--;)
	{
		cin>>s;
		for(i=0;s[i];i++)
		{
			if(i&1)s[i]=122-(s[i]>121);
			else s[i]=97+(s[i]<98);
		}
		cout<<s<<endl;
	}
}