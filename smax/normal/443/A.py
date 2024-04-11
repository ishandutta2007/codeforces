s = input()
k = s[1:-1].split(", ")
k = list(dict.fromkeys(k))
print(0 if s == "{}" else len(k))