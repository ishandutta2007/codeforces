s = gets.chomp
if s.length < 5 or s.scan(/[a-z]/).length < 1 or s.scan(/[A-Z]/).length < 1 or s.scan(/\d/).length < 1
  puts 'Too weak'
else
  puts 'Correct'
end