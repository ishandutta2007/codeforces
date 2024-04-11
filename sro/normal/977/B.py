n=int(input())
s=input()
mxcnt,mxstr=-1,""
for i in range(n-1):
	cnt=0
	for j in range(n-1):
		if s[i]==s[j] and s[i+1]==s[j+1]:
			cnt+=1
	if cnt>mxcnt:
		mxcnt=cnt
		mxstr=s[i:i+2]
print(mxstr)