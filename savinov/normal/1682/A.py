t = int(input())
 
for _ in range(t):
    n = int(input())
    s = input()
    
    pos = (n - 1) // 2
    while pos >= 0 and s[pos] == s[(n - 1) // 2]:
        pos -= 1
    
    print(n - 2 * pos - 2)