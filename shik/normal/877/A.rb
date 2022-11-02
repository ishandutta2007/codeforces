T = %w(Danil Olya Slava Ann Nikita)
s = gets
puts T.map{|t| s.scan(t).size}.inject(:+) == 1 ? "YES" : "NO"