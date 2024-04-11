    #pragma GCC optimize(2)
    #pragma GCC optimize(3)
    #pragma GCC optimize("Ofast")
    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    #define eps 1e-20
    inline int read(){
    	int a=0,fh=0;char c=getchar();
    	while(c>57 or c<48){if(c=='-')fh=1;c=getchar();}
    	while(47<c and c<58){
    		a=a*10+c-48;
    		c=getchar();
    	}
    	return fh?-a:a;
    }
    struct data
    {
    	int x,y;
    	data(int xx=0,int yy=0)
    	{
    		x=xx;
    		y=yy;
    	}
    	bool friend operator <(data a,data b)
    	{
    		if(a.x==b.x)
    			return a.y<b.y;
    		return a.x<b.x;
    	}
    }w;
    set<data>st1,st2;
    int n,top;
    double ans;
    data operator -(data a,data b)
    {
    	return data(a.x-b.x,a.y-b.y);
    }
    bool judge(data a,data b)
    {
    	return a.y*b.x<b.y*a.x;
    }
    #define itset set<data>::iterator
    bool del(itset it,bool op)
    {
    	itset x=it,y=it;
    	x--;y++;
    	if((judge((*y)-(*x),(*y)-(*it))^op))
    	{return 1;}
    	return 0;
    }
    void INS(set<data> &st,data a,bool op)
    {
    	st.insert(a);
    	itset it=st.find(a);
    	if(it!=st.begin()&&it!=(++st.begin()))it--;
    	while(st.size()>2&&it!=st.begin()&&it!=(--st.end())&&del(it,op))
    	{
    		set<data>::iterator _it=it;
    		it--;
    		st.erase(_it);
    	}
    	if(++it==st.end())return;
    	while(st.size()>2&&(it)!=(--st.end())&&it!=st.begin()&&del(it,op))
    	{
    		set<data>::iterator _it=it;
    			it++;
    			st.erase(_it);
    	}
    	if(it==st.end()||++it==(st.end()))return;
    	while(st.size()>2&&(it)!=(--st.end())&&it!=st.begin()&&del(it,op))
    	{
    		set<data>::iterator _it=it;
    			it++;
    			st.erase(_it);
    	}
    }
    bool chk(set<data> &st,data a,bool op)
    {
    	if((*st.begin()).x>a.x||(*(--st.end())).x<a.x)
    	{
    		return 0;
    	}
    	itset it=(st.upper_bound(a)),tmp=it;
    	if(it!=st.begin())
    		tmp--;
    	double y;
    	if((*it).x!=(*tmp).x)y=(double)(*tmp).y+(double)((*it).y-(*tmp).y)*(a.x-(*tmp).x)/((*it).x-(*tmp).x);
    	else
    		y=op?(*tmp).y:(*it).y;
    //	tmp--;
    //	cout<<op<<": "<<(*tmp).x<<" "<<(*tmp).y<<" "<<(*it).x<<" "<<(*it).y<<" "<<y<<"   "<<(it==(--st.end()))<<endl;
    //	if(!(op?y<=((double)(a.y+eps)):(y>=double(a.y-eps))))cout<<"CHK! "<<op<<endl;
    	return op?y<=((double)(a.y+eps)):(y>=double(a.y-eps));
    }
    signed main()
    {
    	n=read();
    	for(int i=1;i<=2;++i)
    	{
    		int op;
    		op=read();w.x=read();w.y=read();
    		st1.insert(w);
    		st2.insert(w);
    	}
    	for(int i=3;i<=n;++i)
    	{
    		int op;
    		op=read();w.x=read();w.y=read();
    	//	cout<<"i: "<<i<<endl;
    		if(op==1)
    		{
    			INS(st1,w,0);
    			INS(st2,w,1);
    		}
    		else
    		{
    			puts((chk(st1,w,0)&chk(st2,w,1))?"YES":"NO");
    		}
    	}
    	return 0;
    }