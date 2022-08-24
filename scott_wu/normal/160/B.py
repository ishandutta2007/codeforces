# http://codeforces.com/problemset/problem/160/B
n=int(input())#steven not a string problem gl i love python i can hashtag everything let's treat it all as string anyway
s = input() #you just sort the lists right and then compare
a,b=s[:n],s[n:] #can i use commas right thx is there a better way to split a string s.split(n)?

c=list(a)
d=list(b) #you can do this also i think? what does that do
#i'm not sure if ; works
#map(sort,(c,d)) #i'm like 80% certain this won't work it maps the function sort to everything in (a,b), 
c.sort()
d.sort()
#it won't work cause my syntax is prolly off
c1, c2 = 0,0 #count #more and #less and check == n wait what are you doing
plist = [(c[i],d[i]) for i in range(n)] # this does work
for x,y in plist:
    if x>y: c2 += 1 #err isn't this checking all pairs x,y?
    if x<y: c1 += 1 #i'm silly

print("YES" if c1==n or c2==n else "NO")

#if this works i'm gonna shit my pants
#runtime error
#what's wrong
#holy shit working. AC
#what did you change?
#ok new problem? i changed for x,y in plist it works curretnly.