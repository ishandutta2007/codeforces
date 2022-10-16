def ask(i):
    print(i)
    s=input()
    if s=='yes':
        return 1
    return 0

pr=[2,4,3,9,5,25,7,49,11,13,17,19,23,29,31,37,41,43,47]
ans=0
for i in pr:
    ans+=ask(i)
if ans>1:
    print("composite")
else:
    print("prime")