mans = ""
for _ in range(int(input())):
    s=input()
    ev=''
    od=''
    for x in s:
    	if x in '13579':
    		od+=x
    	else:
    		ev+=x
    ans=''
    uv=0
    ud=0
    while uv < len(ev) or ud < len(od):
    	if uv == len(ev):
    		ans+=od[ud]
    		ud+=1
    	elif ud == len(od):
    		ans+=ev[uv]
    		uv+=1
    	elif ev[uv]<od[ud]:
    		ans+=ev[uv]
    		uv+=1
    	else:
    		ans+=od[ud];ud+=1
    mans += ans
    mans += '\n'
print(mans)