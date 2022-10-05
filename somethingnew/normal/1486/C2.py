n = int(input())
print("?", 1, n)
secondmx = int(input())
if secondmx != 1:
    print("?", 1, secondmx)
    t = (int(input()) == secondmx)
else:
    t = False    
def zaprl(m):
    print("?", 1, m)
    a = int(input())
    return a != secondmx 
def zaprr(m):
    print("?", m, n)
    a = int(input())
    return a != secondmx 
if t:
    l = 1
    r = secondmx
    while l + 1 < r:
        m = (l+r)//2
        if zaprr(m):
            r = m
        else: 
            l = m
    print('!', l)
   
else:
    l = secondmx
    r = n
    while l + 1 < r:
        m = (l+r)//2
        if zaprl(m):
            l = m
        else: 
            r = m
    print('!', r)