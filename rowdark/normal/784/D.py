A = ['8','$','$','3','6','9','4','7','0','5']

s = raw_input()
ss = ""
for j in map(lambda x: A[int(x)],s):
	ss = j + ss
print "Yes" if ss == s else "No"