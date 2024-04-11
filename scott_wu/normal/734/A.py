n = input()
str = raw_input()

if str.count('A') > str.count('D'):
    print "Anton"
elif str.count('D') > str.count('A'):
    print "Danik"
else:
    print "Friendship"