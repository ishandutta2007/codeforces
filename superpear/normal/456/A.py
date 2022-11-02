n=input()
for i in range(0,n):
    a,b=raw_input().split()
    if a!=b :
        print "Happy Alex"
        break
else:
    print "Poor Alex"