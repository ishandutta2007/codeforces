str = raw_input()
str = "1*" + str + "*1"
n = len(str)
res = 0
for i in range(n):
    if str[i] == '*':
        for j in range(i + 1 , n):
            if str[j] == '*':
                res = max(res , eval(str[:i+1] + "(" + str[i+1:j] + ")" + str[j:]))
print res